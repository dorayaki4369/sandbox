package part1.chapter4;

import java.util.Date;

public class Book implements Comparable<Book>, Cloneable {
	private String title;
	private Date publishDate;
	private String comment;

	@Override
	public int hashCode() {
		int r = 1;
		r = 31 * r + publishDate.hashCode();
		r = 31 * r + title.hashCode();
		return r;
	}

	@SuppressWarnings("unused")
	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (this == null) {
			return false;
		}
		if (!(obj instanceof Book)) {
			return false;
		}

		Book book = (Book) obj;
		if (!publishDate.equals(book.publishDate)) {
			return false;
		}
		if (!title.equals(book.title)) {
			return false;
		}
		return true;
	}

	@Override
	public int compareTo(Book obj) {
		return this.publishDate.compareTo(obj.publishDate);
	}

	@Override
	public Book clone() {
		Book book = new Book();
		book.title = this.title;
		book.publishDate = (Date) this.publishDate.clone();
		book.comment = this.comment;
		return book;
	}
}
